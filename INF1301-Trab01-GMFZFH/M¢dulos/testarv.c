/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTARV.C
*  Letras identificadoras:      TARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa, gm - Gabriel Maia, fh - Felipe Holanda, fz - Felipe Zarattini
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		5.00  gmfzfh 24/03/2015 Implementa��o de complementos da fun��o de efetuar 
*								comandos (inserir) e revis�o
*		4.00  gmfzfh 22/03/2015 Implementa��o de complementos da fun��o de efetuar 
*								comandos (costurar)
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo �rvore. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo �rvore:
*
*     =criar        - chama a fun��o ARV_CriarArvore( )
*     =insdir <Char>
*                   - chama a fun��o ARV_InserirDireita( <Char> )
*                     Obs. nota��o: <Char>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=insesq" <Char>
*                   - chama a fun��o ARV_InserirEsquerda( <Char> )
*     "=irpai"      - chama a fun��o ARV_IrPai( )
*     "=iresq"      - chama a fun��o ARV_IrEsquerda( )
*     "=irdir"      - chama a fun��o ARV_IrDireita( )
*     "=obter" <Char>
*                   - chama a fun��o ARV_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a fun��o ARV_DestruirArvore( )
*	  "=costurar"   - chama a fun��o ARV_CosturaArvore( )
*
/****************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "arvore.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_ARV_CMD       "=criar"
#define     INS_DIR_CMD         "=insdir"
#define     INS_ESQ_CMD         "=insesq"
#define     IR_PAI_CMD          "=irpai"
#define     IR_ESQ_CMD          "=iresq"
#define     IR_DIR_CMD          "=irdir"
#define     OBTER_VAL_CMD       "=obter"
#define     DESTROI_CMD         "=destruir"
#define		COSTURA_CMD			"=costurar"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     �rvore sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{

	ARV_tpCondRet CondRetObtido   = ARV_CondRetOK ;
	ARV_tpCondRet CondRetEsperada = ARV_CondRetFaltouMemoria ;
	/* inicializa para qualquer coisa */

	char ValorEsperado = '?'  ;
	char ValorObtido   = '!'  ;
	char ValorDado     = '\0' ;
	char ChaveDada	   = '\0' ;
	char ChaveObtida   = '!'  ;
	int  NumLidos = -1 ;

	TST_tpCondRet Ret ;

	/* Testar ARV Criar �rvore */

	if ( strcmp( ComandoTeste , CRIAR_ARV_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "i" ,
			&CondRetEsperada ) ;
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_CriarArvore( ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao criar �rvore." );

	} /* fim ativa: Testar ARV Criar �rvore */

	/* Testar ARV Adicionar filho � direita */

	else if ( strcmp( ComandoTeste , INS_DIR_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "cci" , &ChaveDada,
			&ValorDado , &CondRetEsperada ) ;
		if ( NumLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_InserirDireita( ValorDado , ChaveDada ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado inserir �a direita." );

	} /* fim ativa: Testar ARV Adicionar filho � direita */

	/* Testar ARV Adicionar filho � esquerda */

	else if ( strcmp( ComandoTeste , INS_ESQ_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "cci" , &ChaveDada,
			&ValorDado , &CondRetEsperada ) ;
		if ( NumLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_InserirEsquerda( ValorDado , ChaveDada ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao inserir � esquerda." );

	} /* fim ativa: Testar ARV Adicionar filho � esquerda */

	/* Testar ARV Ir para n� pai */

	else if ( strcmp( ComandoTeste , IR_PAI_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "i" ,
			&CondRetEsperada ) ;
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_IrPai( ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao ir para pai." );

	} /* fim ativa: Testar ARV Ir para n� pai */

	/* Testar ARV Ir para n� � esquerda */

	else if ( strcmp( ComandoTeste , IR_ESQ_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "i" ,
			&CondRetEsperada ) ;
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_IrNoEsquerda( ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao ir para esquerda." );

	} /* fim ativa: Testar ARV Ir para n� � esquerda */

	/* Testar ARV Ir para n� � direita */

	else if ( strcmp( ComandoTeste , IR_DIR_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "i" ,
			&CondRetEsperada ) ;
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_IrNoDireita( ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao ir para direita." );

	} /* fim ativa: Testar ARV Ir para n� � direita */

	/* Testar ARV Obter valor corrente */

	else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
	{

		NumLidos = LER_LerParametros( "cci" , &ChaveDada, 
			&ValorEsperado , &CondRetEsperada ) ;
		if ( NumLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_ObterValorCorr( &ValorObtido , &ChaveObtida ) ;

		Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao obter valor corrente." );

		if ( Ret != TST_CondRetOK )
		{
			return Ret ;
		} /* if */

		return TST_CompararChar( ValorEsperado , ValorObtido ,
			"Conte�do do n� est� errado." ) ;

	} /* fim ativa: Testar ARV Obter valor corrente */

	/* Testar ARV Destruir �rvore */

	else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
	{

		ARV_DestruirArvore( ) ;

		return TST_CondRetOK ;

	} /* fim ativa: Testar ARV Destruir �rvore */

	/* Testar ARV Costurar �rvore */

	else if ( strcmp( ComandoTeste , COSTURA_CMD ) == 0 )
	{
		NumLidos = LER_LerParametros( "i" ,
			&CondRetEsperada ) ;
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = ARV_CosturaArvore( ) ;

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
			"Retorno errado ao costurar �rvore." ) ;

	} /* fim ativa: Testar ARV Costurar �rvore */

	CondRetObtido = ARV_ObterValorCorr( &ValorObtido , &ChaveObtida ) ;

	return TST_CondRetNaoConhec ;

} /* Fim fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
