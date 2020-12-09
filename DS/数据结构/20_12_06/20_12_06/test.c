//任意位置插入
void seqListInsert(seqList* ps1,size_t pos,SLDataType val)
{
	if(s1==NULL)
		return;
	if(pos>=0 && pos<=  s1->_size)
	{
		int end=s1->_size;
		while(end>pos)
		{
			s1->_data[end]=si->_data{end-1};
			--end;
		}
		s1->_data[pos]=val;
		++s1->_size;
	}
}
void seqListErase(seqList* s1,int pos)
{
	if(s1==NULL || s1->_size==0)
		return;
	int start=pos+1;
	if(0<=pos && pos<s1->_size)
	{

	}
}



int removeElement(int* nums,int numsSize,int val)
{
	int idx=0;
	for(int i=0;i < numsSize;i++)
	{
		if(nums[i]!=val){
			nums[idx++]=nums[i]
		}
	}
	return idx;
}



int removeDuplicates(int *nums,int numsSize)
{
	if(numsSize<=1)
	{
		return numsSize;
	}
	int i=0,j=1,idx=0;
	while(j<numsSize)
	{
		nums[idx++]=nums[i];
		if(nums[i]==nums[j])
		{
			while(j<numsSize && nums[i]==nums[j])
				++j;
			i=j;
			++j;
		}
		else{
			++i;
			++j;
		}
	}
	if(i=numsSize)
		return idx;
}


void reverse(int* arr,int start,int end)
{
	while(start<end)
	{
		int tmp=arr[start];
		arr[start]=arr[end];
		arr[end]=tmp;
		start++;
		end--;
	}
}

void rotate(int* nums,int numsSize,int k)
{

	if(numsSize<=1)
		return；
	reverse(nums,0,numsSize-k-1);
	reverse(nums,numsSize-k,numsSize-1);
	reverse(nums,0,numsSize-1);
}


 
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    //计算整数K的位数
    int len=0;
    int num=K;
    while(num)
    {
        len++;
        num /= 10;
    }
    //申请数组
    int arrLen =len>ASize?len+1:ASize+1;
    int* arr =(int*)malloc(sizeof(int) * arrLen);
    int step =0;
    int idx=0;
    int end=ASize-1;
    while(end>=0||K>0)
    {
        //逐位相加：上一步进位+对应位的值
        int curSum=step;
        //累加对应位的值
        if(end>=0)
        curSum+=A[end-1];
        if(K>0)
        curSum+=K%10;
        //判断是否有进位
        if(curSum>9)
        {
            step=1;
            //10~19
            curSum-=10;
        }
        else
            step=0;
        arr[idx++]=curSum;
        end--;
        K/=10;
        }
    }
    if(step==1)
        arr[idx++]=1;
    int start=0;
    end=idx-1;
    while(start<end)
    {
        int tmp=arr[start];
        arr[start]=arr[end];
        arr[end]=tmp;
        start++;
        end--;
    }      
}