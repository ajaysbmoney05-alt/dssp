Q1)----------------------------------------------------------------
#include <stdio.h>
int main()
{
 int frames[20], n, pages[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
 int pageCount = sizeof(pages) / sizeof(pages[0]);
 int i, j, k, pointer = 0;
 int pageFaults = 0, hit;
 printf("Enter number of frames: ");
 scanf("%d", &n);
 // Initialize frames
 for (i = 0; i < n; i++)
 frames[i] = -1;
 printf("\nFIFO Page Replacement\n");
 printf("Reference String: ");
 for (i = 0; i < pageCount; i++)
 printf("%d ", pages[i]);
 printf("\n\n");
 printf("Page\tFrames\t\tStatus\n");
 printf("--------------------------------\n");
 for (i = 0; i < pageCount; i++)
 {
 hit = 0;
 // Check whether page is already in memory
 for (j = 0; j < n; j++)
 {
 if (frames[j] == pages[i])
 {
 hit = 1;
 break;
 }
 }
 // Page fault
 if (hit == 0)
 {
 frames[pointer] = pages[i];
 pointer = (pointer + 1) % n;
 pageFaults++;
 }
 // Display current frame contents
 printf("%d\t", pages[i]);
 for (k = 0; k < n; k++)
 {
 if (frames[k] == -1)
 printf("- ");
 else
 printf("%d ", frames[k]);
 }
 if (hit)
 printf("\tHit");
 else
 printf("\tPage Fault");
 printf("\n");
 }
 printf("\nTotal number of page faults = %d\n", pageFaults);
 printf("Total number of page references = %d\n", pageCount);
 printf("Number of page hits = %d\n", pageCount - pageFaults);
 return 0;
}
