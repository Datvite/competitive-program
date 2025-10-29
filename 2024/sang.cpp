void sang1()
{
    memset(sang,sizeof(sang),true);
    sang[1]=false;
    for (long long i=2; i*i<=1000060;i++)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i;j<=1000060;j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
