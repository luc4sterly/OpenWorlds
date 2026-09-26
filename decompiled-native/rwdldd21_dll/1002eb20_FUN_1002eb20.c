// 1002eb20 FUN_1002eb20 [Global]
// programa: RWDLDD21.DLL

int * FUN_1002eb20(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


