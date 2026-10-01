// 10012990 FUN_10012990 [Global]
// program: RWL21.DLL

bool FUN_10012990(FILE *param_1)

{
  int iVar1;
  int local_c;
  float local_8;
  float local_4;
  
  iVar1 = FUN_10020800(param_1,s__f_f_d_1005aaf0);
  if (iVar1 == 3) {
    iVar1 = RwCone(local_4,local_8,local_c);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(5);
  return false;
}


