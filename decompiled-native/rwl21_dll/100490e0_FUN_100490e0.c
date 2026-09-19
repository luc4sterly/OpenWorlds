// 100490e0 FUN_100490e0 [Global]
// programa: RWL21.DLL

int * FUN_100490e0(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


