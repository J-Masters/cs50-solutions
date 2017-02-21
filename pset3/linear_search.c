bool search(int value, int values[], int n)
{
    //make sure n is positive
    if (n < 1)
    {
        return false;
    }

    //look through the haystack (values) to search for the needle (value)
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }

    //return false if the needle isn't found
    return false;
}
