// 00441930 FUN_00441930 [Global]
// program: gamma.dll

void FUN_00441930(int param_1,int param_2,undefined4 *param_3)

{
  int *this;
  int *piStack_14;
  
  this = (int *)(param_1 + -0xc);
  if ((param_2 == 0) && (*(int *)(param_1 + 0x30) != 0)) {
    (**(code **)(*this + 0x70))(this,&DAT_004670e8,&piStack_14);
    FUN_00443eb0(this,0x15,piStack_14,0);
    (**(code **)(*piStack_14 + 8))(piStack_14);
  }
  FUN_00443df0((int)this,param_2,param_3);
  return;
}


