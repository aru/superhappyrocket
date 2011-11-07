//----------------------------------------------------------------------------
template <typename T>
T* new1 (const int bound0)
{
    return new T[bound0];
}
//----------------------------------------------------------------------------
template <typename T>
T** new2 (const int bound0, const int bound1)
{
    const int bound01 = bound0*bound1;
    T** data = new T*[bound1];
    data[0] = new T[bound01];

    for (int i1 = 1; i1 < bound1; ++i1)
    {
        int j0 = bound0*i1;  // = bound0*(i1 + j1) where j1 = 0
        data[i1] = &data[0][j0];
    }
    return data;
}
//----------------------------------------------------------------------------
template <typename T>
T*** new3 (const int bound0, const int bound1, const int bound2)
{
    const int bound12 = bound1*bound2;
    const int bound012 = bound0*bound12;
    T*** data = new T**[bound2];
    data[0] = new T*[bound12];
    data[0][0] = new T[bound012];

    for (int i2 = 0; i2 < bound2; ++i2)
    {
        int j1 = bound1*i2;  // = bound1*(i2 + j2) where j2 = 0
        data[i2] = &data[0][j1];
        for (int i1 = 0; i1 < bound1; ++i1)
        {
            int j0 = bound0*(i1 + j1);
            data[i2][i1] = &data[0][0][j0];
        }
    }
    return data;
}
//----------------------------------------------------------------------------
template <typename T>
T**** new4 (const int bound0, const int bound1, const int bound2,
    const int bound3)
{
    const int bound23 = bound2*bound3;
    const int bound123 = bound1*bound23;
    const int bound0123 = bound0*bound123;
    T**** data = new T***[bound3];
    data[0] = new T**[bound23];
    data[0][0] = new T*[bound123];
    data[0][0][0] = new T[bound0123];

    for (int i3 = 0; i3 < bound3; ++i3)
    {
        int j2 = bound2*i3;  // = bound2*(i3 + j3) where j3 = 0
        data[i3] = &data[0][j2];
        for (int i2 = 0; i2 < bound2; ++i2)
        {
            int j1 = bound1*(i2 + j2);
            data[i3][i2] = &data[0][0][j1];
            for (int i1 = 0; i1 < bound1; ++i1)
            {
                int j0 = bound0*(i1 + j1);
                data[i3][i2][i1] = &data[0][0][0][j0];
            }
        }
    }
    return data;
}
//----------------------------------------------------------------------------
template <typename T>
void delete0 (T*& data)
{
    delete data;
    data = 0;
}
//----------------------------------------------------------------------------
template <typename T>
void delete1 (T*& data)
{
    delete[] data;
    data = 0;
}
//----------------------------------------------------------------------------
template <typename T>
void delete2 (T**& data)
{
    if (data)
    {
        delete[] data[0];
        delete[] data;
        data = 0;
    }
}
//----------------------------------------------------------------------------
template <typename T>
void delete3 (T***& data)
{
    if (data)
    {
        delete[] data[0][0];
        delete[] data[0];
        delete[] data;
        data = 0;
    }
}
//----------------------------------------------------------------------------
template <typename T>
void delete4 (T****& data)
{
    if (data)
    {
        delete[] data[0][0][0];
        delete[] data[0][0];
        delete[] data[0];
        delete[] data;
        data = 0;
    }
}
//----------------------------------------------------------------------------