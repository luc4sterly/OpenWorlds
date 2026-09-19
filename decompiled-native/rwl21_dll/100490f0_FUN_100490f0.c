// 100490f0 FUN_100490f0 [Global]
// programa: RWL21.DLL

ulong * FUN_100490f0(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


