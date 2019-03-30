WiFiServer server(80);
void setup() {
  // put your setup code here, to run once:
  server.begin();
  WiFiClient = Server.available();
String html ="<!DOCTYPE HTML> <html> <head> <meta charset=\"UTF-8\"> <title>Страца с кнопкой</title> </head> <body> <h3>Light </h3>RGB(240, 128, 128) <hr> <h1 style=\"color:blue\">Пусть этот свет укажет вам дорогу</h1> <hr> <h1 style=\"color: tomato\">Учение-свет</h1> <hr> <h1 style=\"color: purple\">https://yandex.ru/?utm_campaign=brand_search_msk%3Aspb&creative=325812998123&gclid=Cj0KCQiA5Y3kBRDwARIsAEwloL7oyKLkcs3L80QvtOTeythRsWFdjcTvdEkk8XAI1zDISBffSRno1ewaArZMEALw_wcB&utm_term=yandex&adgroupid=65697694936&keyword=yandex&utm_medium=search&campaignid=1679697480&utm_source=google</h1> <hr> <h1 style=\"color: orange\">> Время автономной работы:2дн.4часа 8 мнут</h1> <a href=\"C:\Users\LigaRobotov\Documents\base3.html\"> <button> Станция 3</button></a> <a href=\"C:\Users\LigaRobotov\Documents\base 1.html\"> <button> Станция 3</button></a> </body> </html>";
client.println(html);
}

void loop() {
  // put your main code here, to run repeatedly:

}
