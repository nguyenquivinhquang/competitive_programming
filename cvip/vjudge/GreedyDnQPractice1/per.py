function decision(depth, board, curPlayer)
	
	if (depth == maxDepth || checkEndGame == true)
		return score(board, curPlayer)
	move = findAllPossibleMove(board, nextPlayer)

	if (move.size() == 0)
		return decision(depth + 1, board, nextPlayer)

	for (each move)
		val =  decision(depth + 1, boardForNextPlayer, nextPlayer) 
		if (curPlayer is Bot)
			bestMove = max(bestMove, val)
		if (curPlayer is Human)
			bestMove = min(bestMove, val)
	return bestMove


function finalDecision(board) 
	move = move = findAllPossibleMove(board, human)
	
	for (each move)
		val = decision(2, boardForHuman, human)
		if val > bestMove
			bestMove = val
			moveRes = this move
		if val == bestMove
			chose randomly(this move and moveRes)
	return moveRes
	