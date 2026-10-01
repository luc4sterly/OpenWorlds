// 0042dfe3 FUN_0042dfe3 [Global]
// program: sfmain.exe

void FUN_0042dfe3(void)

{
  unkbyte10 in_ST0;
  unkbyte10 in_ST7;
  undefined2 uVar1;
  undefined2 uStack00000016;
  undefined4 in_stack_00000014;
  
  uStack00000016 = (undefined2)((uint)in_stack_00000014 >> 0x10);
  uVar1 = (undefined2)((unkuint10)in_ST0 >> 0x40);
  FUN_0042da44((int)in_ST7,(uint)((unkuint10)in_ST7 >> 0x20),(ushort)((unkuint10)in_ST7 >> 0x40),
               (int)in_ST0,(uint)((unkuint10)in_ST0 >> 0x20),CONCAT22(uStack00000016,uVar1));
  return;
}


