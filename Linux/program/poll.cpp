#include <stdio.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIMEOUT 5 /* Poll timeout, in sec */
int main(void) {
  struct pollfd fds[2];
  int ret;

  /* watch stdin for input */
  fds[0].fd = STDIN_FILENO;
  fds[0].events = POLLIN;

  /* watch stdout for ability to write */
  fds[1].fd = STDOUT_FILENO;
  fds[1].events = POLLOUT;

  /* All set, block! */
  ret = poll(fds, 2, TIMEOUT * 1000);

  if (ret == -1) {
    perror("poll");
    return 1;
  }
  if (!ret) {
        printf("%d seconds elapsed\n", TIMEOUT);
        return 0;
  }
  if (fds[0].events & POLLIN) {
        printf("stdin is readable\n");
       printf("stdin: %d\n", fds[0].events);
  }
  if (fds[1].events & POLLOUT) {
       printf("stdout is writable\n");
  }
  return 0;
}
