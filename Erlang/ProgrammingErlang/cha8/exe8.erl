-module(exe8).
-export([funnum/1,mmfun/0,commonfun/0,least_fun/0]).

%%  (1) Count how many functions in a Module

funnum(M) ->
    L = M:module_info(exports),
    countlist(L).

%%  (2) 1.Find which module export the most functions

mmfun() ->
    A = [[funnum(Name),Name] || {Name,_} <- code:all_loaded()],
    lists:max(A).

%% (2) 2.Which function name is  most common

commonfun() ->
    L = time_list(),
    lists:max(L).

%% (2) 3.Which function only appear once

least_fun() ->
    L = time_list(),
    [Y||{X,Y} <- L,X =:= 1].


time_list() ->
    A = fun_list(),
    [{count_times(Name,A), Name} || {Name,_} <- A].
    
fun_list() ->
    A = [Name:module_info(exports) || {Name,_} <- code:all_loaded()],
    lists:flatten(A).

%% count the number of time a element appears in a list
count_times(_, []) -> 0;
count_times(X, [{X,_}|XS]) -> 1 + count_times(X, XS);
count_times(X, [_|XS]) -> count_times(X, XS).
%% count element number in a list
countlist([]) -> 0;
countlist([_|T]) -> 
    1 + countlist(T).


