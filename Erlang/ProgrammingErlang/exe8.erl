-module(exe8).
-export([funnum/1,mmfun/0,commonfun/0]).

%%  (1) Count how many functions in a Module

funnum(M) ->
    L = M:module_info(exports),
    countlist(L).

%%  (2) 1.Find which module export the most functions

mmfun() ->
    A = [[funnum(Name),Name] || {Name,_} <- code:all_loaded()],
    lists:max(A).

countlist([]) -> 0;

countlist([_|T]) -> 
    1 + countlist(T).


