// 0040b0b0 FUN_0040b0b0 [Global]
// program: gamma.dll

undefined1 __cdecl
FUN_0040b0b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  uint unaff_EBX;
  uint unaff_ESI;
  uint *unaff_EDI;
  undefined1 local_38;
  uint *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20 [8];
  short local_18;
  
  local_38 = 0;
  iVar1 = FUN_0040b030(param_1,param_2,&DAT_00466e50,&param_3,1,0x800,&local_24);
  if (iVar1 == 0) {
    unaff_EBX = FUN_0040a420(param_1,param_4);
    if (unaff_EBX == 0) {
      FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e568,
                   s_INetscapeRegistry__unable_to_all_0046e57c);
    }
    else {
      unaff_ESI = FUN_0040a420(param_1,param_5);
      if (unaff_ESI == 0) {
        FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e568,
                     s_INetscapeRegistry__unable_to_all_0046e57c);
      }
      else {
        unaff_EDI = FUN_00454a10(0x20);
        if (unaff_EDI == (uint *)0x0) {
          FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e568,
                       s_INetscapeRegistry__unable_to_all_0046e57c);
        }
        else {
          Ordinal_8(unaff_EDI + 4);
          *(undefined2 *)(unaff_EDI + 4) = 8;
          unaff_EDI[6] = unaff_EBX;
          Ordinal_8(unaff_EDI);
          *(undefined2 *)unaff_EDI = 8;
          unaff_EDI[2] = unaff_ESI;
          local_2c = 2;
          local_30 = 0;
          local_28 = 0;
          local_34 = unaff_EDI;
          Ordinal_8(local_20);
          iVar1 = FUN_0040afd0(param_1,param_2,local_24,&DAT_00466e50,0x400,1,&local_34,local_20,0,0
                              );
          if ((-1 < iVar1) && (local_18 != 0)) {
            local_38 = 1;
          }
        }
      }
    }
  }
  if (unaff_EBX != 0) {
    Ordinal_6(unaff_EBX);
  }
  if (unaff_ESI != 0) {
    Ordinal_6(unaff_ESI);
  }
  if (unaff_EDI != (uint *)0x0) {
    FUN_00454a60(unaff_EDI);
  }
  return local_38;
}


