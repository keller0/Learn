-module(test3).
-compile(export_all).

start(N, M, Message) when N > 0,M > 0 ->
    statistics(runtime),
    statistics(wall_clock),
    spawn(fun() ->ring(N,M,Message) end).


ring(N, M, Message) ->
    Fun = fun(_,Next) -> spawn(fun() -> loop(Next) end) end,
    Ln =  lists:foldl(Fun, self(), lists:seq(1, N)),
    register(lastnode, Ln),
    io:format("lastnode is ~p~n",[Ln]),
    lastnode ! {msg,Message},
    loop(lastnode, M).

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
            io:format("node ~p stoped~n",[self()])
    end.


trace(Next, Msg) ->
    io:format("~p --> ~p :~w~n",[self(), Next, Msg]).
stat() ->
    {_, Time1} = statistics(runtime),
    {_, Time2} = statistics(wall_clock),
    io:format("~p,~p~n",[ Time1, Time2]).
