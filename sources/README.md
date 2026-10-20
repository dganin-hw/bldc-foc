# Источники

Документация производителей, по которой выбраны компоненты, посадочные места и
режимы работы. Сами документы в репозиторий не копируются: права на них у
производителей, здесь только ссылки.

## Основная плата

| Компонент | Документ |
|---|---|
| STM32G431CBT6 | [ST, документация](https://www.st.com/resource/en/datasheet/stm32g431cb.pdf) |
| STM32G4, таймеры и АЦП | [ST RM0440, справочное руководство](https://www.st.com/resource/en/reference_manual/rm0440-stm32g4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) |
| DRV8323RS | [TI, документация DRV832x](https://www.ti.com/lit/ds/symlink/drv8323.pdf) |
| PSMN7R0-60YS | [Nexperia, документация](https://assets.nexperia.com/documents/data-sheet/PSMN7R0-60YS.pdf) |
| WSK2512R0200FEA | [Vishay WSK2512](https://www.vishay.com/docs/30108/wsk2512.pdf) |
| AP2112K-3.3 | [Diodes AP2112](https://www.diodes.com/assets/Datasheets/AP2112.pdf) |
| SRN6045TA-330M | [Bourns SRN6045TA](https://www.bourns.com/docs/product-datasheets/srn6045ta.pdf) |
| EEUFR1V471 | [Panasonic, описание](https://industrial.panasonic.com/ww/products/pt/aluminum-cap-lead/models/EEUFR1V471), [чертёж серии FR](https://industrial.panasonic.com/cdbs/www-data/pdf/RDF0000/ABA0000C1259.pdf) |
| Phoenix Contact 1715721 | [MKDS 1,5/2-5,08](https://www.phoenixcontact.com/en-us/products/printed-circuit-board-terminal-mkds-15-2-508-1715721) |
| Phoenix Contact 1715734 | [MKDS 1,5/3-5,08](https://www.phoenixcontact.com/en-us/products/printed-circuit-board-terminal-mkds-15-3-508-1715734) |
| Littelfuse 01110005MR | [клипсы серии 111](https://www.littelfuse.com/assetdocs/111-mr-series-datasheet?assetguid=bc74b1bc-7507-4786-9a59-0f9eb414f154) |
| Eaton BK1/S501-2-R | [Eaton S501](https://www.eaton.com/content/dam/eaton/products/electronic-components/resources/data-sheet/eaton-s501-ceramic-tube-fuses-data-sheet.pdf) |
| E-Switch TL3342F160QG | [чертёж](https://configured-product-images.s3.amazonaws.com/2D/specs/TL3342F160QG.pdf) |

Коды LCSC для всех позиций есть в [перечне компонентов](../hardware/dev-board/manufacturing/bom/BOM.csv).

## Плата энкодера

| Компонент | Документ |
|---|---|
| AS5047P | [ams OSRAM, документация](https://look.ams-osram.com/m/d05ee39221f9857/original/AS5047P-DS000324.pdf), [копия на Mouser](https://www.mouser.com/datasheet/2/588/AS5047P_DS000324_3_00-1843440.pdf) |
| JST GH, SM06B-GHS-TB | [JST, серия GH](https://www.jst-mfg.com/product/pdf/eng/eGH.pdf) |

## Стенд

| Что | Документ |
|---|---|
| T-Motor MN2212 V2.0 | [страница мотора](https://store.tmotor.com/cn/product/mn2212-v2-motor-navigator-type.html), [чертёж PDF](https://cn.tmotor.com/uploadfile/downloads/tmotor-mn2212-motor-2d-drawings.pdf), [модель STEP](https://cn.tmotor.com/uploadfile/downloads/tmotor-mn2212-motor-3d-model.step) |
| Тонкая гайка M5, DIN 439B | [Aspen Fasteners](https://www.aspenfasteners.com/m5-0-8-din-439b-metric-thin-hex-jam-nuts-brass/) |
| Шайба M5, DIN 125 | [Würth](https://eshop.wuerth.de/Flat-washer-For-hexagon-head-bolts-and-nuts-DIN-125-plain-brass-WSH-DIN125-A-BRS-D53/04005.sku/en/US/EUR/) |

## 4-in-1 ESC

| Что | Документ |
|---|---|
| STM32G474 | [ST DS12288](https://www.st.com/resource/en/datasheet/stm32g474ve.pdf) |
| Запуск АЦП от HRTIM | [ST AN5094](https://www.st.com/resource/en/application_note/dm00442720-migrating-between-stm32f334303-lines-and-stm32g474xxg431xx-microcontrollers-stmicroelectronics.pdf) |
| HRTIM | [ST AN4539, HRTIM cookbook](https://www.st.com/resource/en/application_note/dm00121475-hrtim-cookbook-stmicroelectronics.pdf) |
| Два мотора на одном МК | [ST EVSPIN32G4-DUAL](https://www.st.com/en/evaluation-tools/evspin32g4-dual.html) |
| BSC028N06NS | [Infineon, документация](https://www.infineon.com/assets/row/public/documents/24/49/infineon-bsc028n06ns-datasheet-en.pdf) |
| WSKW06121L000FEA | [Vishay WSKW0612](https://www.vishay.com/docs/30332/wskw0612.pdf) |
| CSS4J-4026 (запасной вариант шунта) | [Bourns CSS4J-4026](https://www.bourns.com/docs/product-datasheets/css4j-4026.pdf) |
| LMR36510 | [TI, документация](https://www.ti.com/lit/ds/symlink/lmr36510.pdf) |

## Библиотеки KiCad

Посадочные места в `FocDev.pretty` и `FocEnc.pretty` скопированы из стандартных
библиотек KiCad 10, условия использования описаны в
[лицензии библиотек KiCad](https://www.kicad.org/libraries/license/). Символ
DRV8323RS и символ разъёма платы энкодера нарисованы по таблицам выводов из
документации производителей.
