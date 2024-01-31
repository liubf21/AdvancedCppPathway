# 现代C++


[Modern C++ 选讲](https://docs.eesast.com/docs/languages/C&C++/modern_cpp)

[Modern C++ Best Practices and Features](https://medium.com/@chittaranjansethi/modern-c-best-practices-and-features-9cd22951e5a7)

## C++11
C++11 是 C++ 语言的一个重要的更新，引入了众多新特性，使得编程更加简洁和高效。以下列出了一些 C++11 的关键特性，并配有示例代码。

1. **自动类型推导 `auto`**
   
    使用 `auto` 关键字可以让编译器自动推导变量的类型。
   
   ```cpp
   auto i = 42;  // i is an int
   auto s = "hello"; // s is a const char*
   ```

2. **基于范围的 for 循环**
   
   使用这种循环可以简化对容器的遍历。
   
   ```cpp
   std::vector<int> v = {1, 2, 3, 4, 5};
   for (auto num : v) {
       std::cout << num << " ";
   }
   ```

3. **nullptr**
   
   为了区分 0 和空指针，引入了 `nullptr`。
   
   ```cpp
   int* p = nullptr;
   ```

4. **Lambda 表达式**
   
   Lambda 允许定义匿名函数对象。
   
   ```cpp
   auto sum = [](int a, int b) -> int {
       return a + b;
   };
   std::cout << sum(3, 4); // Outputs 7
   ```

5. **移动语义和 `std::move`**
   
   这使得资源所有权可以从一个对象转移到另一个对象，提高效率。
   
   ```cpp
   std::string str1 = "hello";
   std::string str2 = std::move(str1); // str2 now owns the data, str1 is empty
   ```

6. **智能指针**
   
   如 `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr` 使得内存管理变得更加简单。
   
   ```cpp
   std::unique_ptr<int> p1(new int(42));
   std::shared_ptr<int> p2 = std::make_shared<int>(58);
   ```

7. **变长模板参数**

   允许模板接受可变数量的参数。

   ```cpp
   template<typename... Args>
   void print(Args... args) {
       (std::cout << ... << args) << "\n";
   }
   
   print(1, 2.0, "three");
   ```

8. **初始化列表 `initializer_list`**
   
   使得初始化容器更加方便。
   
   ```cpp
   std::vector<int> v = {1, 2, 3, 4, 5};
   ```

9. **`constexpr`**
   
   在编译时计算函数或变量的值。
   
   ```cpp
   constexpr int square(int n) {
       return n * n;
   }
   
   constexpr int x = square(4); // x is 16
   ```

10. **委托构造函数**
   
   一个构造函数可以调用同类中的另一个构造函数。
   
   ```cpp
   class MyClass {
   public:
       MyClass() : MyClass(42) {}
       MyClass(int x) : value(x) {}
   private:
       int value;
   };
   ```


以下是一些较为详细的列表，介绍了C++11 引入的新特性：

1. **核心语言特性**:

    - **Rvalue 引用与移动语义** (`std::move`, `&&`)
    - **基于范围的 for 循环**
    - **自动类型推导** (`auto`)
    - **decltype** 
    - **Lambda 表达式** (`[capture](params) -> ret { body; }`)
    - **`nullptr`** 替代 `NULL` 和 `0` 作为指针的空值
    - **静态断言** (`static_assert`)
    - **委托构造函数**
    - **继承构造**
    - **显式虚函数重写** (`override` 和 `final`)
    - **用户定义的字面量**
    - **尾返回类型**
    - **类型别名声明** (`using`)
    - **类型推导和 `auto`** (函数返回类型推导)
    - **`constexpr`** 函数
    - **模板增强**
      - 变长模板参数
      - 默认模板参数
    - **`noexcept`** 规范和操作符
    - **右值引用** (`&&`), 用于实现移动语义和完美转发
    - **强枚举类型** (`enum class`)
    - **原始字符串字面量**，使得字符串可以包含原始内容，如 `R"(raw_content)"`
    - **线程局部存储** (`thread_local`)
    - **对 `= default` 和 `= delete` 的支持** 来显式地指定或删除函数的默认实现
    - **属性** (`[[attribute]]`), 例如 `[[noreturn]]`, `[[deprecated]]` 和 `[[nodiscard]]` (部分属性可能在 C++14 或更高版本中引入)
    - **统一的初始化语法** 和 **初始化列表** (`std::initializer_list`)
  
2. **标准库的增强**:

    - **智能指针**: `std::shared_ptr`, `std::unique_ptr`, 和 `std::weak_ptr`
    - **STL 容器的增强**
      - `std::array`: 固定大小的数组
      - `std::forward_list`: 单向链表
      - `std::unordered_map`, `std::unordered_set`, `std::unordered_multimap`, `std::unordered_multiset`: 基于哈希的容器
    - **`std::move`**, `std::forward` 和其他实用函数
    - **正则表达式支持** (`<regex>`)
    - **线程支持库** (`<thread>`, `<mutex>`, `<condition_variable>`, `<atomic>`, 等)
    - **时间工具** (`<chrono>`)
    - **新的算法和函数对象**
    - **随机数生成** (`<random>`)
    - **元组** (`std::tuple`)
    - **新的数值限制** (`<cstdint>`, `<cinttypes>`)
    - **功能库** (`<functional>`)
    - **C++ 与 C 的互操作性改进**
  
3. **其他特性**:

    - 强化了 C++ 的类型推导机制，包括 `decltype`, `auto`, 尾返回类型等
    - 新的类型特性 (`<type_traits>`)
    - 更好的异常支持和堆栈展开
    - 对 UTF-8, UTF-16, 和 UTF-32 的原生支持

## C++14

C++14 是 C++11 的一个较小的更新，但它为语言和标准库引入了多项有用的改进和新特性。以下是 C++14 的关键特性和改进：

1. **核心语言特性**:

    - **变量模板**:
      ```cpp
      template<typename T>
      constexpr T pi = T(3.1415926535897932385);
      ```

    - **泛型 lambda**:
      ```cpp
      auto adder = [](auto a, auto b) { return a + b; };
      ```

    - **Lambda 捕获初始化器**:
      ```cpp
      int x = 4;
      auto lambda = [y = x + 4] { return y; };
      ```

    - **返回类型推导**:
      ```cpp
      auto func() -> decltype(auto) { /* ... */ }
      ```

    - **二进制字面量**:
      ```cpp
      int binary = 0b1010;
      ```

    - **数字分隔符**:
      ```cpp
      long long billion = 1'000'000'000;
      ```

    - **`[[deprecated]]` 属性**:
      ```cpp
      [[deprecated("Use newFunc() instead")]]
      void oldFunc();
      ```

    - **扩展的 `constexpr`**:
      C++14 中的 `constexpr` 函数可以包含更多的语句，如条件语句和循环。

    - **推导 lambda 返回类型**:
      C++14 允许 lambda 函数在没有尾返回类型的情况下推导返回类型。

    - **`decltype(auto)`**:
      允许为自动类型推导的变量或函数返回类型使用完美转发的类型。

    - **`std::make_unique` 函数**:
      类似于 C++11 中的 `std::make_shared`，但是用于 `std::unique_ptr`。

2. **标准库的增强**:

    - **新的库特性检查宏**，例如 `__cpp_lib_integer_sequence` 和 `__cpp_lib_generic_associative_lookup`。
    
    - **用户定义的字面量**，例如 `std::string` 的 `"s" suffix`。
    
    - **增强的元组功能**，如 `std::get<Type>(tuple)` 重载和 `std::make_tuple()` 对智能指针的特殊处理。
    
    - **交换和比较增强**:
        - `std::exchange()` 函数，用于交换值并返回旧值。
        - `std::less<void>` 和其他比较操作的透明比较。

    - **增强的工具**:
        - `std::integral_constant` 的增强，如 `::value_type` 成员类型。
        - `std::integer_sequence` 和相关工具。
        - `std::result_of` 和 `decltype(auto)` 的增强。

    - **增强的内存管理功能**:
        - `std::make_unique` 和 `std::shared_timed_mutex`。
        - `std::align` 函数。
      
    - **动态数组扩展**: 
        - `std::dynarray` (虽然最后没有在标准中实现)。

    - **C++14 中还有许多其他的小型库增强和增加**。

3. **其他特性**:

    - **更宽松的 `constexpr`**：在 C++11 中，`constexpr` 函数有许多限制，例如它们只能包含单个返回语句。C++14 放宽了这些限制，使 `constexpr` 函数更加灵活。
  
    - **模板别名的模板参数推导**。
  
    - **强化的可聚合类型定义**。

尽管 C++14 的改进相对于 C++11 较小，但这些改进对于开发者来说仍然非常有用，使得编写现代 C++ 代码更加简洁、易读和高效。

## C++17

C++17 为 C++ 语言和标准库带来了许多重要的新特性和增强。以下是 C++17 的主要特性和改进：

1. **核心语言特性**:

    - **结构化绑定**: 允许同时对多个变量进行初始化。
      ```cpp
      std::pair<int, std::string> p = {1, "one"};
      auto [num, str] = p;
      ```

    - **if 初始化** 和 **switch 初始化**: 在条件语句中进行变量声明。
      ```cpp
      if (auto it = map.find(key); it != map.end()) { /* ... */ }
      ```

    - **内联变量**: 主要用于头文件中的常量和内联函数的静态变量。
      ```cpp
      inline constexpr int var = 10;
      ```

    - **`constexpr` lambda**: 允许 lambda 函数在编译时执行。
    - **`auto` 作为函数参数类型** (仅用于模板).
      ```cpp
      template <typename T>
      void func(T auto x) { /* ... */ }
      ```

    - **模板参数的推导**：可以省略模板参数，让编译器自行推导。
      ```cpp
      std::pair p(2, 4.5); // deduces to std::pair<int, double>
      ```

    - **折叠表达式**: 处理可变数量的函数参数更为简单。
      ```cpp
      template<typename... Args>
      auto sum(Args... args) { return (... + args); }
      ```

    - **使用 `,` 和 `...` 的新语法**，如 `template <typename... Ts> void foo(Ts... args);`.
    
    - **`[[nodiscard]]` 属性**: 如果函数的返回值被忽略，则编译器会发出警告。
    - **`[[maybe_unused]]` 属性**: 用于声明可能未使用的变量、参数等，以避免编译器警告。
    - **`[[fallthrough]]` 属性**: 在 `switch` 语句中明确表示无意中的“贯穿”行为。
  
2. **标准库的增强**:

    - **文件系统库** (`<filesystem>`): 提供了跨平台的文件和目录操作功能。
    - **并行算法**: `std::for_each`, `std::transform` 等都有并行版本。
    - **`std::optional`**: 可选值容器。
    - **`std::any`**: 可以存储任意类型的对象。
    - **`std::variant`**: 类型安全的联合类型。
    - **`std::string_view`**: 提供对字符串的非持有型、轻量级的视图。
    - **增强的 `std::tuple`**: 新增 `std::apply`, `std::make_from_tuple` 等。
    - **新增 `std::byte` 类型**：提供了字节级操作。
    - **`std::invoke`**: 泛型调用功能。
    - **`std::bool_constant`**: 用作类型元编程的布尔常量。
    - **`std::sample`**: 从容器中随机选取元素。
    - **`std::shared_mutex`**: 允许多个读者和一个写者同时访问。
    - **`std::scoped_lock`**: 锁定多个互斥体，避免死锁。
    - **`std::hardware_constructive_interference_size` 和 `std::hardware_destructive_interference_size`**：为并行算法提供缓存行信息。

3. **其他特性**:

    - **强化的 `constexpr`**: 新增对更多操作的支持，如 `if` 和 `loop`。
    - **`using` 声明在模板中**：允许模板中的 `using` 声明继承构造函数。
    - **嵌套的命名空间定义**：
      ```cpp
      namespace A::B::C { /* ... */ }
      ```

    - **直接列表初始化超越花括号**：解决了“最令人烦恼的解析”问题。
    - **动态内存的改进**，如 `std::aligned_alloc`。

C++17 是一个重要的版本，它为现代 C++ 编程引入了许多有趣和有用的特性，进一步简化了代码，提高了效率，同时也为未来的 C++ 标准奠定了基础。

## C++20

C++20 是 C++ 标准的一个重大更新，引入了大量新特性和显著改进。这些改进使得 C++ 更加现代化，提高了编码效率，同时增强了语言的灵活性和表达能力。以下是 C++20 的主要特性和改进：

1. **核心语言特性**:

    - **概念和约束** (`concepts`): 提供了一种对模板参数进行类型检查的方法。
      ```cpp
      template<typename T>
      requires std::integral<T>
      T add(T a, T b) {
          return a + b;
      }
      ```

    - **三元运算符重载**：允许重载 `operator<=>` 以支持全序关系。
    
    - **模块** (`modules`): 代替传统的头文件和源文件模型，提高编译效率和代码封装性。
    
    - **协程** (`coroutines`): 提供了对协程的原生支持，使得异步编程更加简洁。
    
    - **初始化列表构造**：使得聚合类型可以使用构造函数初始化列表。
    
    - **常量求值** (`consteval`): 强制函数在编译时求值。
    
    - **立即函数** (`constinit`): 确保静态/线程局部变量在编译时初始化。
    
    - **范围式 `for` 循环的改进**：引入了 `begin()` 和 `end()` 的自定义点。
    
    - **Lambda 改进**：
      - 默认构造和赋值。
      - 模板 Lambda。

2. **标准库的增强**:

    - **Ranges 库**: 提供了一个基于范围的编程范式。
    - **`std::span`**: 提供了对数组和 STL 容器的视图。
    - **`std::bit_cast`**: 类似于 C 的类型强制转换，但更安全。
    - **`std::jthread`**: 管理线程的新方式，支持“加入”的自动化。
    - **同步流** (`syncstream`): 用于线程安全的 IO 操作。
    - **`std::format`**: 提供了类似于 Python 的格式化字符串功能。
    - **`std::erase` 和 `std::erase_if`**: 用于从容器中删除元素。
    - **`std::to_array`**: 用于将 C 风格数组转换为 `std::array`。
    - **`std::make_shared_for_overwrite` 和 `std::make_unique_for_overwrite`**：为未初始化的数据创建智能指针。
    - **`std::atomic` 和 `std::atomic_ref` 的增强**: 对更多类型提供原子操作支持。
    - **`std::source_location`**: 提供了执行代码的位置信息，类似于宏 `__LINE__` 和 `__FILE__`。

3. **其他特性**:

    - **P1381：标准库扩展**：例如 `std::latch`, `std::barrier`。
    - **更多的编译时计算支持**：加强了 `constexpr` 的能力。
    - **特征测试宏**：用于测试编译器是否支持某些特性。
    - **泛化的聚合初始化**。
    - **日期和时间库的增强**。
    - **更多的数学常数和工具**。
    - **协程的标准库支持**：例如 `std::coroutine_handle`。

C++20 的这些新增特性对于提升 C++ 的能力和易用性是一个巨大的飞跃，特别是概念、模块和协程的引入，为未来的 C++ 版本和现代 C++ 编程提供了强大的基础。