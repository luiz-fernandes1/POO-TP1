//
// Created by joaov on 30/06/2021.
//

#include "arquivos.h"
#include <vector>
#include "../../pessoas/funcionarios/vendedor/vendedor.hpp"
#include "../../pessoas/funcionarios/tosador/tosador.hpp"
#include "../../pessoas/clientes/cliente.hpp"
#include "../../estabelecimento/compras_pagamentos/compras.hpp"
#include "../../estabelecimento/compras_pagamentos/pagamentos.hpp"
#include "../../estabelecimento/produto_servico/servicos.hpp"

Arquivos::Arquivos() {}

Arquivos::~Arquivos() {}

int Arquivos::validaLogin(int user, string *login, string *senha) {
    int x;
    switch (user) {
        case 1:
            if (*login == "admin" && *senha == "admin") {
                cout << "entrou no admin" << endl;
                return 1;
            } else { return 0; }
            break;
        case 2:
            x = buscaNoBanco(user, login, senha);
            if (x == 1) {
                cout << "entrou no vendedor" << endl;
                return 1;
            } else { return 0; }
            break;
        case 3:
            x = buscaNoBanco(user, login, senha);
            if (x == 1) {
                cout << "entrou no veterinario" << endl;
                return 1;
            } else { return 0; }
            break;
        default:
            return 0;
            break;
    }
    return 0;
}

int Arquivos::buscaNoBanco(int user, string *login, string *senha) {
    return 1;
}

void Arquivos::inicializaArquivo() {
    int variavel = 0;
    FILE *arquivo = fopen("vendedor.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo);
    fclose(arquivo);

    FILE *arquivo1 = fopen("veterinario.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo1);
    fclose(arquivo1);

    FILE *arquivo2 = fopen("tosador.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo2);
    fclose(arquivo2);

    FILE *arquivo3 = fopen("cliente.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo3);
    fclose(arquivo3);

    FILE *arquivo4 = fopen("compras.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo4);
    fclose(arquivo4);

    FILE *arquivo5 = fopen("pagamentos.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo5);
    fclose(arquivo5);

    FILE *arquivo6 = fopen("produtos.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo6);
    fclose(arquivo6);

    FILE *arquivo7 = fopen("servicos.dat", "wb");
    fwrite(&variavel, sizeof(int), 1, arquivo7);
    fclose(arquivo7);
}

//pessoas
//leitura e escrita de arquivos em memoria secundaria  - Vendedor
void Arquivos::escreverArquivoVendedor(int tamanho, vector<Vendedor> &vendedores) {
    FILE *arquivo = fopen("vendedor.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fwrite(&vendedores, sizeof(Vendedor), tamanho, arquivo);
    fclose(arquivo);
}

void Arquivos::lerArquivoVendedor(int tamanho, vector<Vendedor> &vendedores) {

    FILE *vendedorArq;
    if ((vendedorArq = fopen("vendedor.dat", "rb")) == NULL) {
        cout << "Erro na criação do arquivo binário." << endl;
    } else {
        fread(&tamanho, sizeof(int), 1, vendedorArq);
        if (tamanho != 0) {
            fread(&vendedores, sizeof(Vendedor), tamanho, vendedorArq);
        }
    }
    fclose(vendedorArq);
}

//leitura e escrita de arquivos em memoria secundaria  - Veterinario
void Arquivos::escreverArquivoVeterinario(int tamanho, vector<Veterinario> &veterinario) {
    FILE *veterinarioArq = fopen("veterinario.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, veterinarioArq);
    fwrite(&veterinario, sizeof(Veterinario), tamanho, veterinarioArq);
    fclose(veterinarioArq);
}

void Arquivos::lerArquivoVeterinario(int tamanho, vector<Veterinario> &veterinario) {
    FILE *veterinarioArq = fopen("veterinario.dat", "rb");
    fread(&tamanho, sizeof(int), 1, veterinarioArq);
    fread(&veterinario, sizeof(Veterinario), tamanho, veterinarioArq);
    fclose(veterinarioArq);
}

//leitura e escrita de arquivos em memoria secundaria  - Tosador
void Arquivos::escreverArquivoTosador(int tamanho, vector<Tosador> &tosador) {
    FILE *tosadorArq = fopen("tosador.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, tosadorArq);
    fwrite(&tosador, sizeof(Tosador), tamanho, tosadorArq);
    fclose(tosadorArq);
}

void Arquivos::lerArquivoTosador(int tamanho, vector<Tosador> &tosador) {
    FILE *tosadorArq = fopen("tosador.dat", "rb");
    fread(&tamanho, sizeof(int), 1, tosadorArq);
    fread(&tosador, sizeof(Tosador), tamanho, tosadorArq);
    fclose(tosadorArq);
}

//leitura e escrita de arquivos em memoria secundaria - Cliente
void Arquivos::escreverArquivoCliente(int tamanho, vector<Cliente> &cliente) {
    FILE *clienteArq = fopen("cliente.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, clienteArq);
    fwrite(&cliente, sizeof(Cliente), tamanho, clienteArq);
    fclose(clienteArq);
}

void Arquivos::lerArquivoCliente(int tamanho, vector<Cliente> &cliente) {
    FILE *clienteArq = fopen("cliente.dat", "rb");
    fread(&tamanho, sizeof(int), 1, clienteArq);
    fread(&cliente, sizeof(Cliente), tamanho, clienteArq);
    fclose(clienteArq);
}


//estabelecimentos
// leitura e escrita de arquvios em memoria secundaria - Compras
void Arquivos::escreverArquivoCompras(int tamanho, vector<Compras> &compras) {
    FILE *comprasArq = fopen("compras.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, comprasArq);
    fwrite(&compras, sizeof(Compras), tamanho, comprasArq);
    fclose(comprasArq);
}

void Arquivos::lerArquivoCompras(int tamanho, vector<Compras> &compras) {
    FILE *comprasArq = fopen("compras.dat", "rb");
    fread(&tamanho, sizeof(int), 1, comprasArq);
    fread(&compras, sizeof(Compras), tamanho, comprasArq);
    fclose(comprasArq);
}

// leitura e escrita de arquivos em memoria secundaria - Pagamentos
void Arquivos::escreverArquivoPagamentos(int tamanho, vector<Pagamentos> &pagamentos) {
    FILE *pagamentosArq = fopen("pagamentos.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, pagamentosArq);
    fwrite(&pagamentos, sizeof(Pagamentos), tamanho, pagamentosArq);
    fclose(pagamentosArq);
}

void Arquivos::lerArquivoPagamentos(int tamanho, vector<Pagamentos> &pagamentos) {
    FILE *pagamentosArq = fopen("pagamentos.dat", "rb");
    fread(&tamanho, sizeof(int), 1, pagamentosArq);
    fread(&pagamentos, sizeof(Pagamentos), tamanho, pagamentosArq);
    fclose(pagamentosArq);
}


// leitura e escrita de arquivos em memoria secundaria - Produtos
void Arquivos::escreverArquivoProdutos(int tamanho, vector<Produtos> &produtos) {
    FILE *produtosArq = fopen("produtos.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, produtosArq);
    fwrite(&produtos, sizeof(Produtos), tamanho, produtosArq);
    fclose(produtosArq);
}

void Arquivos::lerArquivoProdutos(int tamanho, vector<Produtos> &produtos) {
    FILE *produtosArq = fopen("produtos.dat", "rb");
    fread(&tamanho, sizeof(int), 1, produtosArq);
    fread(&produtos, sizeof(Produtos), tamanho, produtosArq);
    fclose(produtosArq);
}


// leitura e escrita de arquivos em memoria secundaria - Servicos
void Arquivos::escreverArquivoServico(int tamanho, vector<Servicos> &servico) {
    FILE *servicoArq = fopen("servicos.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, servicoArq);
    fwrite(&servico, sizeof(Servicos), tamanho, servicoArq);
    fclose(servicoArq);
}

void Arquivos::lerArquivoServico(int tamanho, vector<Servicos> &servico) {
    FILE *servicoArq = fopen("servicos.dat", "rb");
    fread(&tamanho, sizeof(int), 1, servicoArq);
    fread(&servico, sizeof(Servicos), tamanho, servicoArq);
    fclose(servicoArq);
}