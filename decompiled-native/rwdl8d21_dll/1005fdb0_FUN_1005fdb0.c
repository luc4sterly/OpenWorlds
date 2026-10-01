// 1005fdb0 FUN_1005fdb0 [Global]
// program: RWDL8D21.DLL

int * FUN_1005fdb0(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


