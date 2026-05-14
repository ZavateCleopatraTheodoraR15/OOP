#include<vector>// nu era 
#include<iostream>// nu era
template<typename T>
void sortareLista(std::vector<T>& v)
{
    int n = v.size();
    for (int i = 0; i <= n; i++)//pana la n-1 ,nu n
        for (int j = i; j < n; j++)//de la i+1 nu i
        {
            if (v[i] < v[j]) std::swap(v[i], v[j]);// if (v[i] > v[j]) 
            if (v[i] == v[j]) continue;// nu e nevoie
        }
}
int main()
{
    std::vector<int> v = {1,3,7,6,4,5,2};

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    std::cout << "             ";

    sortareLista(v);

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    int ok = 1;
    int invers = 1;
    for(int i=0;i<v.size();i++)
        for (int j = i+1; j < v.size()-1; j++)
        {
            if (v[i] > v[j]) 
            { 
                ok=0; 
                break; 
            }
            if (v[i] != v[v.size() - i])
                invers = 0;
        }
    if (invers == 1)
        std::cout << "Sortare invers";

    else if (ok == 1)
        std::cout << "Sortare corecta";

    else std::cout << "Sortare incorecta";
};
