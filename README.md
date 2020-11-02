# RadixTree

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d8cf6d5c6e314ae09cd3cca8cf9a2577)](https://app.codacy.com/gh/reficul0/RadixTree?utm_source=github.com&utm_medium=referral&utm_content=reficul0/RadixTree&utm_campaign=Badge_Grade)

Реализация Radix Tree.

Пример:

Символ $ обозначает признак завершения строки. 
Добавление "aleksey". \
  "aleksey"$ 

Добавление "sasha". 
Корень становится пустой строкой без признака завершения. \
"" \
├ "aleksey"$ \
└ "sasha"$ 

Добавление "aleks" 
"" \
├ "aleks"$ \
│ └ "ey"$ \
└ "sasha"$ 

Добавление "alek" 
"" \
├ "alek"$ \
│ └ "s"$ \
│   └ "ey"$ \
└ "sasha"$ 

Добавление "alesha" приводит к расщеплению узла "alek" при этом узел "ale" без признака завершения. \
"" \
├ "ale" \
│ ├ "k"$ \
│ │ └ "s"$ \
│ │   └ "ey"$ \
│ └ "sha"$ 
