#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void initialize(int N, int M, int field[N][M]);
void print_field(int N, int M, int field[N][M]);
void update_state(int N, int M, int state[N][M], int field[N][M]);
void update_field(int N, int M, int state[N][M], int field[N][M]);
int count_cells(int N, int M, int field[N][M], int x, int j);
int main() {
        int N = 25;
        int M = 80;
        int field[N][M];
        int state[N][M];
        int quit = 0;
        int ch = 0;
        initialize(N, M, field);
        freopen("/dev/tty", "r", stdin);
        int speed = 55000;
        fd_set rfds;
        struct timeval tv;
        int retval;
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        tv.tv_sec = 0;
        tv.tv_usec = 1000;
        print_field(N, M, field);
        system("stty -echo");
        while (quit != 1) {
                usleep(speed);
                system("clear");
                print_field(N, M, field);
                system("stty raw");
                retval = select(1, &rfds, NULL, NULL, &tv);
                if (retval == -1) {
                        perror("select()");
                } else if (retval) {
                    ch = getchar();
                } else {
                  FD_SET(0, &rfds);
                }
                switch (ch) {
                case 113:
                        quit = 1;
                        break;
                case 43:
                        if ((speed - 15000) > 0) {
                                speed -= 15000;
                        }
                        break;
                case 45:
                        speed += 15000;
                        break;
                }
                system("stty cooked");
                update_state(N, M, state, field);
                update_field(N, M, state, field);
        }
        system("stty cooked");
        system("stty echo");
}

void initialize(int N, int M, int field[N][M]) {
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        scanf("%d", &field[i][j]);
                }
        }
}

void print_field(int N, int M, int field[N][M]) {
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        if (field[i][j] == 0) {
                                printf(" ");
                        } else {
                                printf("0");
                        }
                }
                printf((i == N - 1) ? "" : "\n");
        }
}

void update_state(int N, int M, int state[N][M], int field[N][M]) {
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        state[i][j] = count_cells(N, M, field, i, j);
                }
        }
}

int count_cells(int N, int M, int field[N][M], int i, int j) {
        int count = 0;
        int x, y;
        for (int k = 0; k <= 2; k++) {
                for (int l = 0; l <= 2; l++) {
                        x = (i + k - 1 + N) % N;
                        y = (j + l - 1 + M) % M;
                        if ((field[x][y] == 1) && !((x == i) && (y == j))) {
                                count++;
                        }
                }
        }
        return count;
}

void update_field(int N, int M, int state[N][M], int field[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if ((state[i][j] < 2) || (state[i][j] > 3)) {
        field[i][j] = 0;
      }
      if (state[i][j] == 3) {
        field[i][j] = 1;
      }
    }
  }
}
