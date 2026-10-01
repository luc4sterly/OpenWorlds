// 1005fdc0 FUN_1005fdc0 [Global]
// program: RWDL8D21.DLL

ulong * FUN_1005fdc0(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


