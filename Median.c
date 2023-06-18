#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int *nums;
    nums = (int*) malloc((nums1Size + nums2Size)*sizeof(int));
    int i = 0;
    int j = 0;
    int l = nums1Size + nums2Size;
    int med = l / 2;
    printf("%d %d\n",l,med);
    
    for(int k = 0; k <= med; k++)
    {
    	if ( i < nums1Size && j < nums2Size)
    	{
		    if (nums1[i]<nums2[j])
		    {
		        nums[k] = nums1[i];		        
		        i++;
		    }
		    else
		    {
		        nums[k] = nums2[j];		 
		        j++;
		    }
		}
		else if (i < nums1Size)
		{
			nums[k] = nums1[i];
			i++;
		}
		else 
		{
			nums[k] = nums2[j];
			j++;
		}
    }
    double res = l % 2 == 0 ? (nums[med - 1] + nums[med]): (2*nums[med]);
    return res/2;
}

int main()
{
	int *a,*b;
	a = (int*) malloc (5*sizeof(int));
	b = (int*) malloc (5*sizeof(int));
	for (int i = 0; i<4; i++)
		scanf("%d",&a[i]);
	for (int i = 0; i<5; i++)
		scanf("%d",&b[i]);
	double x = findMedianSortedArrays(a,4,b,5);
	printf("%lf",x);
}
