Projeto que visa resolver o problema classico do jantar dos filosofos, este problema visa resolver a questão de data racing e deadlock em acesso de dados, a saber temos 
um numero n qualquer de filosofos sentados em uma mesa, cada filosofo tem um garfo para mas para que ele possa se alimentar ele precisa de dois garfos, então a unica 
forama de um filosofo se alimentar é emprestando um garfo de um de seus amigos (da esquerda ou da direita), mas claramente um garfo não pode ser usado por dois filosofos 
ao mesmo tempo. para complicar mais o problema o programa recebe parametros que ditam quanto tempo um filosofo demora para comer e por quanto tempo esse filosofo pode ficar
sem comer, o desafio consiste em conseguir proteger os garfos de data racing sem gerar deadlock, em outras palavras os filosofos devem ser capazes de dividir os garfos
para se alimentar em grupo sem maiores problemas
