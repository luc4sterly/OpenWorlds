// 1002eb30 FUN_1002eb30 [Global]
// program: RWDLDD21.DLL

ulong * FUN_1002eb30(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


