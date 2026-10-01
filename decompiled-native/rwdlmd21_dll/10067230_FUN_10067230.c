// 10067230 FUN_10067230 [Global]
// program: rwdlmd21.dll

int * FUN_10067230(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


