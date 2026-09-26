// 0042dbaf FUN_0042dbaf [Global]
// programa: sfmain.exe

void FUN_0042dbaf(void)

{
  code *pcVar1;
  unkbyte10 Var2;
  unkbyte10 extraout_ST1;
  undefined2 uVar3;
  undefined2 uStack00000046;
  undefined4 in_stack_00000044;
  
  uStack00000046 = (undefined2)((uint)in_stack_00000044 >> 0x10);
  pcVar1 = (code *)swi(6);
  Var2 = (*pcVar1)();
  uVar3 = (undefined2)((unkuint10)extraout_ST1 >> 0x40);
  FUN_0042da44((int)Var2,(uint)((unkuint10)Var2 >> 0x20),(ushort)((unkuint10)Var2 >> 0x40),
               (int)extraout_ST1,(uint)((unkuint10)extraout_ST1 >> 0x20),
               CONCAT22(uStack00000046,uVar3));
  return;
}


