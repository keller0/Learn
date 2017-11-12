-module(qs).
-export([qsort/1]).

qsort([]) ->
    [];
qsort([Povit|T]) ->
    qsort([X || X <- T, X < Povit])
        ++[Povit]++
        qsort([X || X <- T, X >= Povit]).
                     
                
