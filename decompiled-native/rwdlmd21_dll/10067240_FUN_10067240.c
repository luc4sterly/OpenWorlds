// 10067240 FUN_10067240 [Global]
// program: rwdlmd21.dll

ulong * FUN_10067240(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


