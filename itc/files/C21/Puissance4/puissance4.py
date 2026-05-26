import p4guy

game = p4guy.Puissance4()

exit = False
while not exit:
    event, values = game.view.read()
    if event=='Exit' or event==p4guy.sg.WIN_CLOSED:
        game.view.Close()
        exit = True
    elif event=='Reset':
        game.reset()
    elif event=='Undo':
        game.undo()
    elif event=='Switch':
        game.switch()
    else:
        game.play(p4guy.conversion(event))