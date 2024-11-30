# Backlog do Produto

# Cadastro e Reservas de Voos

## Funcionalidades

### 1. Cadastro de Passageiro
- **Importância:** 40
- **Estimativa:** 3 dias
- **Descrição:** No menu principal, selecione a opção "Cadastrar Passageiro". Preencha todas as informações necessárias, como nome, CPF, data de nascimento e endereço. O código do passageiro deve ser gerado automaticamente.
- **Critério de Aceitação:**
  - Deve criar uma instância da classe `Passageiro`, que herda de `Pessoa`.
  - Informações obrigatórias: nome, CPF, data de nascimento, endereço.
  - Código gerado automaticamente.
- **Notas:** Nenhuma

---

### 2. Cadastro de Tripulante
- **Importância:** 40
- **Estimativa:** 3 dias
- **Descrição:** No menu principal, selecione a opção "Cadastrar Tripulante". Preencha as informações necessárias, como nome, CPF, data de nascimento, endereço e função (ex.: piloto, comissário). O código do tripulante deve ser gerado automaticamente.
- **Critério de Aceitação:**
  - Deve criar uma instância da classe `Tripulante`, que herda de `Pessoa`.
  - Informações obrigatórias: nome, CPF, data de nascimento, endereço, função.
  - Código gerado automaticamente.
- **Notas:** Nenhuma

---

### 3. Cadastro de Voo
- **Importância:** 50
- **Estimativa:** 4 dias
- **Descrição:** No menu principal, selecione a opção "Cadastrar Voo". Preencha todas as informações, como número do voo, destino, origem, data, horário e tripulantes associados.
- **Critério de Aceitação:**
  - Deve criar uma instância da classe `Voo`.
  - Informações obrigatórias: número do voo, destino, origem, data, horário, tripulantes.
  - O voo só pode ser cadastrado se houver pelo menos um tripulante de cada função necessária (ex.: piloto e comissário).
  - Validar a presença mínima de tripulantes antes de permitir o cadastro.
- **Notas:** Nenhuma

---

### 4. Cadastro de Assento
- **Importância:** 35
- **Estimativa:** 2 dias
- **Descrição:** No menu principal, selecione a opção "Cadastrar Assento". Alocar assentos específicos em voos cadastrados.
- **Critério de Aceitação:**
  - Deve criar uma instância da classe `Assento`.
  - Informações obrigatórias: número do assento, voo associado.
  - O assento deve ser vinculado a um voo previamente cadastrado.
- **Notas:** Nenhuma

---

### 5. Reservar Voo
- **Importância:** 50
- **Estimativa:** 2 dias
- **Descrição:** No menu principal, selecione a opção "Reservar Voo". Passageiros podem reservar assentos disponíveis. Assentos ocupados não podem ser reservados novamente.
- **Critério de Aceitação:**
  - Deve-se criar um objeto da classe `Reserva`.
  - A reserva é vinculada a um passageiro e a um assento disponível no voo.
  - Validar se o assento está ocupado antes de confirmar a reserva.
- **Notas:** Integrar à classe `Passageiro` uma função para criar reservas.

---

### 6. Pesquisar Pessoas
- **Importância:** 20
- **Estimativa:** 1 dia
- **Descrição:** No menu principal, selecione a opção "Pesquisar". Insira o nome ou parte do nome para buscar passageiros ou tripulantes cadastrados.
- **Critério de Aceitação:**
  - Função na classe `Passageiro` que permite realizar buscas.
  - Deve retornar uma lista com os resultados encontrados ou informar que não há correspondências.
- **Notas:** Nenhuma

