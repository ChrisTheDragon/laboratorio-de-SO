
def add_processo(id, tempo, prioridade):
    global processos
    novo = [id, tempo, prioridade, 0]
    processos.append(novo)
    
def RoundRobin(processo, quantum):
    finalizados = len(processo)
    
    while (finalizados >= 0):
        i = 0
        fim = ''
        while(i < len(processo)):
            temp = processo[i][1]
            processo[i][1] -= quantum
            processo[i][3] = temp - abs(processos[i][1])
            #print(f"Processo {processo[i][0]}\tTempo Restante: {processo[i][1]}\tExecução: {abs(processos[i][3])}")
            if(processo[i][1] > 0):
                print(f"Processo {processo[i][0]}\tExecução: {abs(processos[i][3])}")
            elif (processo[i][1] <= 0):
                finalizados -= 1
                print(f"Processo {processo[i][0]}\tExecução: {abs(processos[i][3])}*")
                #print(f"Processo {processo[i][0]} foi finalizado")
                processo.pop(i)
            i += 1
        if (finalizados == 0): break



processos = []

add_processo("P1", 200, 5)
add_processo("P2", 120, 9)
add_processo("P3", 400, 0)
add_processo("P4", 90, 4)

RoundRobin(processos, 11)