-module(user_default).

-compile(export_all).

hello() ->
    "Hello Cai how are you?".

away(Time) ->
    io:format("Cai is away and will be back in ~w minutes ~n",
              [Time]).
