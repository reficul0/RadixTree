[![Codacy Badge](https://app.codacy.com/project/badge/Grade/738d7cd8fc74461b8095ab4d138564f2)](https://www.codacy.com/gh/reficul0/RadixTree/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=reficul0/RadixTree&amp;utm_campaign=Badge_Grade)
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](https://github.com/RocketChat/Rocket.Chat/raw/master/LICENSE)

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
