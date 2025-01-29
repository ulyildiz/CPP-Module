class a
{
private:
    /* data */
public:
    a(/* args */);
    void asd()
    {
        if (this == 0)
            return ;
    }
    ~a();
};

a::a(/* args */)
{
}

a::~a()
{
}

int main(int argc, char const *argv[])
{
    a *a1 = 0;
    a1->asd();
    return 0;
}
