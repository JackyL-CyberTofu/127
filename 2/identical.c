int identical( int arr1[], int arr2[], unsigned int len)
{
    int i;
    //CHECK IF IT'S EMPTY
    if (len == 0)
    {
        return 1;
    }
    //CHECK LETTER BY LETTER IF THEY ARE THE SAME
    for (i=0; i<len; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }    
    }
    return 1;
}
