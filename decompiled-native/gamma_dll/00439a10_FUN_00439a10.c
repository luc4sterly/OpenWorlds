// 00439a10 FUN_00439a10 [Global]
// program: gamma.dll

undefined4 * __thiscall
FUN_00439a10(void *this,int *param_1,char *param_2,int param_3,undefined4 param_4)

{
  undefined **local_10;
  undefined4 *local_c;
  
  FUN_0042f2c0(this);
  *(undefined ***)this = &PTR_LAB_00476e90;
  *(undefined ***)this = &PTR_LAB_00476e78;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00475fac;
  *(undefined4 *)((int)this + 0xc) = 0;
  FUN_00437d00(&local_10,param_1,param_2,param_3,param_4);
  FUN_0043b240((void *)((int)this + 8),(int)&local_10);
  local_10 = &PTR_LAB_00475fac;
  if (local_c != (undefined4 *)0x0) {
    FUN_0042f340(local_c);
  }
  FUN_0042f320(&local_10);
  return this;
}


