#include <iostream>
using namespace std;

class MovieStore
{
private:
    string* names;
    int* ids;
    float* rating;
    int Size;
    int currentSize;

    int c_ind = 0;
    bool mem_fin = 0;

public:
    MovieStore()
    {
        names = new string[5];
        ids = new int[5];
        rating = new float[5];
        Size = 5;
        currentSize = 0;
    }
    MovieStore(int a)
    {
        names = new string[a];
        ids = new int[a];
        rating = new float[a];
        Size = a;
        currentSize = 0;
    }
    MovieStore& operator[](string str)
    {
        bool exists = 0;

        if (currentSize <= Size)
        {
            for (int i = 0; i < Size; ++i)
                if (names[i] == str)
                {
                    exists = 1;
                    c_ind = i;
                    break;
                }
            if (!exists)
            {
                names[currentSize] = str;
                ids[currentSize] = currentSize + 1;
                c_ind = currentSize;
                currentSize++;
            }
        }
        else
        {
            cout << "Memory finished, movie can't be added\n";
            mem_fin = 1;
        }
        return *this;
    }
    MovieStore& operator=(int rat)
    {
        if (!mem_fin)
            rating[c_ind] = rat;
        else
        {
            cout << "Memory finished, overwritin last memory\n";
            rating[Size - 1] = rat;
        }
        return *this;
    }
    float operator[](int id_no)
    {
        if (id_no >= 0 && id_no <= currentSize)
        {
            if (names[id_no - 1] != "")
                return float(rating[id_no - 1]);
        }
        else
        {
            cout << "id not found\n";
            return -1;
        }
    }
    MovieStore& operator=(MovieStore& sto)
    {
        delete[] names;
        delete[] ids;
        delete[] rating;
        Size = sto.Size;
        currentSize = sto.currentSize;
        mem_fin = sto.mem_fin;
        c_ind = sto.c_ind;
        names = new string[Size];
        ids = new int[Size];
        rating = new float[Size];

        for (int i = 0; i < Size; ++i)
        {
            names[i] = sto.names[i];
            ids[i] = sto.ids[i];
            rating[i] = sto.rating[i];
        }
        return *this;
    }
    ~MovieStore()
    {
        delete[] names;
        delete[] ids;
        delete[] rating;
        names = NULL;
        ids = NULL;
        rating = NULL;
    }

    //friend ostream& operator<<(ostream&, float);
    friend ostream& operator<<(ostream&, MovieStore&);
};
//ostream& operator<<(ostream& out, float f)
//{
//    if (f == -1)
//        out << "id not found\n";
//    else
//        out << f;
//    return out;
//}
ostream& operator<<(ostream& out, MovieStore& sto)
{   
    out << "Id\tMovie\t\t\tRating\n";
    
    for (int i = 0; i < sto.currentSize; ++i)
        out << sto.ids[i] << "\t" << sto.names[i] << "\t\t\t" << sto.rating[i] << endl;
    return out;
}

int main()
{
    MovieStore s1, s2(10); // create two stores of size 5 and 10

    s1["Hobbit"] = 4.5;
    /* If previously not added, add a movie with average rating of 4.5
    If already exist, overwrite rating by 4.5
    If memory finished print "Memory finished overwriting rating of last movie"
    And Update accordingly */

    s1["Lord of the Rings"] = 5;

    cout << s1[2] << endl;
    /* get rating for movie id 2 (Lord of the Rings => 5).
    If id not found print "id not found"
    And return -1 rating .*/

    s2 = s1; // copies elements from sl to s2

    s1["Lion King"] = 8;
    cout << s2; // should display all the Movie store information
    return 0;
}
