// 00403235 FUN_00403235 [Global]
// programa: gdkup.exe

void FUN_00403235(void)

{
  uint in_EAX;
  uint uVar1;
  uint extraout_ECX;
  
  if (in_EAX != 0) {
    (*(code *)PTR_FUN_00408b54)();
    uVar1 = DAT_00408b28;
    if (((DAT_0040b434 == 0) || (in_EAX < DAT_0040b434)) || (*(uint *)(DAT_0040b434 + 8) <= in_EAX))
    {
      for (; (*(uint *)(uVar1 + 8) != 0 && ((in_EAX < uVar1 || (*(uint *)(uVar1 + 8) <= in_EAX))));
          uVar1 = *(uint *)(uVar1 + 8)) {
      }
    }
    FUN_004044c6();
    if ((extraout_ECX < DAT_00408b2c) && (DAT_00408b30 < *(uint *)(extraout_ECX + 0x14))) {
      DAT_00408b30 = *(uint *)(extraout_ECX + 0x14);
    }
    DAT_0040b46c = 0;
    DAT_0040b434 = extraout_ECX;
    (*(code *)PTR_FUN_00408b5c)();
  }
  return;
}


