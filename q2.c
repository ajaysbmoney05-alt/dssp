#include <stdio.h>
int main()
{
 int n, m, i, j, p;
 printf("Enter processes and resources: ");
 scanf("%d%d", &n, &m);
 int a[n][m], max[n][m], need[n][m];
 int total[m], avail[m], req[m], work[m], finish[n];
 printf("Enter total resources: ");
 for(j=0;j<m;j++) scanf("%d",&total[j]);
 printf("Enter Allocation Matrix:\n");
 for(i=0;i<n;i++)
 for(j=0;j<m;j++) scanf("%d",&a[i][j]);
 printf("Enter Maximum Matrix:\n");
 for(i=0;i<n;i++)
 for(j=0;j<m;j++) {
 scanf("%d",&max[i][j]);
 need[i][j]=max[i][j]-a[i][j];
 }
 /* Calculate Available */
 for(j=0;j<m;j++) {
 avail[j]=total[j];
 for(i=0;i<n;i++) avail[j]-=a[i][j];
 }
 printf("\nNeed Matrix:\n");
 for(i=0;i<n;i++) {
 for(j=0;j<m;j++) printf("%d ",need[i][j]);
 printf("\n");
 }
 printf("\nEnter process number: ");
 scanf("%d",&p);
 printf("Enter request: ");
 for(j=0;j<m;j++) scanf("%d",&req[j]);
 /* Request <= Need and Available */
 for(j=0;j<m;j++)
 if(req[j]>need[p][j] || req[j]>avail[j]) {
 printf("Request cannot be granted immediately.\n");
 return 0;
 }
 /* Temporary allocation */
 for(j=0;j<m;j++) {
 avail[j]-=req[j];
 a[p][j]+=req[j];
 need[p][j]-=req[j];
 work[j]=avail[j];
 }
 for(i=0;i<n;i++) finish[i]=0;
 /* Safety check */
 for(int k=0;k<n;k++)
 for(i=0;i<n;i++)
 if(!finish[i]) {
 int ok=1;
 for(j=0;j<m;j++)
 if(need[i][j]>work[j]) ok=0;
 if(ok) {
 for(j=0;j<m;j++)
 work[j]+=a[i][j];
 finish[i]=1;
 }
 }
 for(i=0;i<n;i++)
 if(!finish[i]) {
 printf("Request cannot be granted.\n");
 return 0;
 }
 printf("Request can be granted immediately.\n");
 return 0;
}
