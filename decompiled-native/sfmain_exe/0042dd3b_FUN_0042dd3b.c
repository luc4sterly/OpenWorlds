// 0042dd3b FUN_0042dd3b [Global]
// program: sfmain.exe

unkbyte10 FUN_0042dd3b(void)

{
  unkbyte10 in_ST0;
  unkbyte10 in_ST3;
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uStack00000016;
  undefined4 in_stack_00000014;
  
  uStack00000016 = (undefined2)((uint)in_stack_00000014 >> 0x10);
  uVar1 = (undefined4)in_ST0;
  uVar2 = (uint)((unkuint10)in_ST0 >> 0x20);
  uVar3 = (undefined2)((unkuint10)in_ST0 >> 0x40);
  FUN_0042da44((int)in_ST3,(uint)((unkuint10)in_ST3 >> 0x20),(ushort)((unkuint10)in_ST3 >> 0x40),
               uVar1,uVar2,CONCAT22(uStack00000016,uVar3));
  return CONCAT28(uVar3,CONCAT44(uVar2,uVar1));
}


