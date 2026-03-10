# Exemplos de Execução — Estatística Aplicada

## Como compilar e executar

```bash
gcc -o estatistica estatistica.c -lm
```

## Como compilar e executar

```bash
./estatistica
```

---

## Exemplo 1 — Correlação Positiva Forte

**Dados de entrada:**

| Par | x | y |
|-----|---|---|
| 1   | 1 | 2 |
| 2   | 2 | 4 |
| 3   | 3 | 5 |
| 4   | 4 | 4 |
| 5   | 5 | 5 |

**Saída:**

```
============================================================
   ESTATÍSTICA APLICADA — Correlação e Regressão Linear
============================================================

Quantos pares de valores (x, y) deseja inserir? 5

Digite os 5 pares de valores:
  Par  1  →  x: 1   y: 2
  Par  2  →  x: 2   y: 4
  Par  3  →  x: 3   y: 5
  Par  4  →  x: 4   y: 4
  Par  5  →  x: 5   y: 5

============================================================
                      RESULTADOS
============================================================

  Número de pares analisados : 5

  [ Médias ]
    Média de x  (x̄) = 3.0000
    Média de y  (ȳ) = 4.0000

  [ Coeficiente de Correlação de Pearson ]
    r = 0.7746
    Interpretação: correlação forte
    Direção: positiva (quando x aumenta, y tende a aumentar)

  [ Regressão Linear Simples ]
    Coeficiente angular  b = 0.6000
    Coeficiente linear   a = 2.2000

    Equação da reta: y = 2.2000 + 0.6000 * x

  Deseja prever um valor de y para um x informado? (s/n): s
  Informe o valor de x: 6
  → Para x = 6.0000, o valor previsto de y é: 5.8000

  Deseja prever outro valor? (s/n): n
```

---

## Exemplo 2 — Correlação Negativa Muito Forte

**Dados de entrada:**

| Par | x  | y  |
|-----|----|----|
| 1   | 1  | 10 |
| 2   | 2  | 8  |
| 3   | 3  | 5  |
| 4   | 4  | 2  |

**Saída:**

```
============================================================
                      RESULTADOS
============================================================

  Número de pares analisados : 4

  [ Médias ]
    Média de x  (x̄) = 2.5000
    Média de y  (ȳ) = 6.2500

  [ Coeficiente de Correlação de Pearson ]
    r = -0.9959
    Interpretação: correlação muito forte
    Direção: negativa (quando x aumenta, y tende a diminuir)

  [ Regressão Linear Simples ]
    Coeficiente angular  b = -2.7000
    Coeficiente linear   a = 13.0000

    Equação da reta: y = 13.0000 + -2.7000 * x
```

---

## Exemplo 3 — Dados com 6 Pares (correlação muito forte)

**Dados de entrada:**

| Par | x  | y  |
|-----|----|----|
| 1   | 2  | 4  |
| 2   | 4  | 5  |
| 3   | 6  | 7  |
| 4   | 8  | 8  |
| 5   | 10 | 9  |
| 6   | 12 | 12 |

**Saída:**

```
============================================================
                      RESULTADOS
============================================================

  Número de pares analisados : 6

  [ Médias ]
    Média de x  (x̄) = 7.0000
    Média de y  (ȳ) = 7.5000

  [ Coeficiente de Correlação de Pearson ]
    r = 0.9833
    Interpretação: correlação muito forte
    Direção: positiva (quando x aumenta, y tende a aumentar)

  [ Regressão Linear Simples ]
    Coeficiente angular  b = 0.7571
    Coeficiente linear   a = 2.2000

    Equação da reta: y = 2.2000 + 0.7571 * x

  Deseja prever um valor de y para um x informado? (s/n): s
  Informe o valor de x: 7
  → Para x = 7.0000, o valor previsto de y é: 7.5000
```

> **Observação:** Para x = 7 (que é exatamente a média de x), o valor previsto é 7.5 — igual à média de y. Isso é uma propriedade matemática da regressão linear: a reta sempre passa pelo ponto (x̄, ȳ).