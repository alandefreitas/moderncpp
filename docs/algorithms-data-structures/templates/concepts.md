# Concepts

!!!note "Concepts"

    Concepts (C++20) define named sets of template requirements. 

    Class templates, function templates, and non-template functions (typically members of class templates) may be 
    associated with a template constraint, which specifies the requirements on template arguments, which can be used 
    to select the most appropriate function overloads and template specializations. 

    Each concept is a predicate, evaluated at compile time, and becomes a part of the interface of a template where 
    it is used as a constraint:

{{ code_snippet("snippets/templates/CMakeLists.txt", "concepts", "cmake") }}

<hr>

{{ all_code_snippets("snippets/templates/concepts.cpp") }}

