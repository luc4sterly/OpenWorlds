// 10012550 FUN_10012550 [Global]
// program: RWL21.DLL

bool FUN_10012550(FILE *param_1)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = FUN_10020800(param_1,s__f_f_f_d_1005aae4);
  if (iVar1 == 4) {
    iVar1 = RwCylinder(local_4,local_8,local_c,local_10);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(5);
  return false;
}


