// 10011300 FUN_10011300 [Global]
// programa: RWL21.DLL

bool FUN_10011300(FILE *param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = FUN_10020800(param_1,s__f_f_f_1005aab4);
  if (iVar1 == 3) {
    iVar1 = RwBlock(local_4,local_8,local_c);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(5);
  return false;
}


