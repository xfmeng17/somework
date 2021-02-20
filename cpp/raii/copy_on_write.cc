#include <memory>
#include <iostream>
 
struct Foo {
    Foo(int n = 0) noexcept : bar(n) {
        std::cout << "Foo: constructor, bar = " << bar << '\n';
    }
    ~Foo() {
         std::cout << "Foo: destructor, bar = " << bar << '\n';
    }
    int getBar() const noexcept { return bar; }
private:
    int bar;
};
 
int main()
{
    std::shared_ptr<Foo> sptr = std::make_shared<Foo>(1);
    std::shared_ptr<Foo> sptr1 =std::make_shared<Foo>(2);
    sptr1 = sptr;
    std::cout << "The first Foo's bar is " << sptr->getBar() << "\n";
 
    // reset the shared_ptr, hand it a fresh instance of Foo
    // (the old instance will be destroyed after this call)
    std::cout << "The first Foo's #1 use_count=" << sptr1.use_count() << "\n";
    sptr.reset(new Foo);
    std::cout << "The first Foo's #2 use_count=" << sptr1.use_count() << "\n";
    
    std::cout << "The second Foo's bar is " << sptr->getBar() << "\n";
}