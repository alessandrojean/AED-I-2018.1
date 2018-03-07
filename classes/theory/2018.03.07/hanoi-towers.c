#include <stdio.h>
#include <stdlib.h>

void moveDisk (int disksNum, int dir) {
	printf("Move Disk %d to the %s\n", disksNum, 
					dir>0 ? "right" : "left");
}

// dir == -1 -> left; dir == 1 -> right 
// (move in a circular way)
void HanoiTower (int disksNum, int dir) {
	if (disksNum == 0)
		return;
	HanoiTower(disksNum-1, -dir);
	moveDisk(disksNum, dir);
	HanoiTower(disksNum-1, -dir);
}

int main (int argc, char ** argv) {
  int n;
  printf("Number of disks: ");
  scanf("%d", &n);
  
  HanoiTower(n, 1);

  return EXIT_SUCCESS;
}