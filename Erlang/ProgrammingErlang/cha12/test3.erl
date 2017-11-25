%% take me a long time to understand this code learn from github
%% https://github.com/jsquared21/Pragmatic-Programming-Erlang\
%% /blob/master/Ch_12/ring.erl
%% Use lists:foldl to make a process ring.
%% Each prcosess remember the previous process's pid so those
%% message will be passed by in reverse order.
-module(test3).
-export([start/3]).

start(N, M, Message) when N > 0,M > 0 ->
    statistics(runtime),
    P = spawn(fun() ->ring(N,M,Message) end),
    io:format("first process is ~p~n",[P]).

ring(N, M, Message) ->
    Fun = fun(_,Next) -> spawn(fun() -> loop(Next) end) end,
    P =  lists:foldl(Fun, self(), lists:seq(1, N)),
    io:format("last process is ~p~n~n",[P]),
    P ! {msg,Message},
    loop(P, M).

loop(Next, M) ->
    case M =:= 1 of
        true ->
            Next ! stop,
            stat();
        false->
            receive
                {msg,Message} ->
                    trace(Next, Message),
                    Next ! {msg, Message},
                    loop(Next, M-1)
            end
    end.

loop(Next) ->
    receive
        {msg,Message} ->
            trace(Next, Message),
            Next ! {msg, Message},
            loop(Next);
        stop ->
            Next ! stop
    after
        3000 ->
            io:format("process~p stoped~n",[self()])
    end.


trace(Next, Msg) ->
    io:format("~p --> ~p :~w~n",[self(), Next, Msg]).
stat() ->
    {_, Time1} = statistics(runtime),
    io:format("Cost CPU time ~p ms~n",[Time1]).
