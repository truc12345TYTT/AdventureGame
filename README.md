# AdventureGame
<h2> Bài tập lớn môn LTNC Lớp 22 N3 của Trúc &lt;3 👋 </h2>

<h2> *Thể loại: Adventure* </h2>

<h3> 👨🏻‍💻 Nguồn đã tham khảo </h3>


- 🌐 &nbsp; Youtube: https://www.youtube.com/playlist?list=PL-K0viiuJ2RctP5nlJlqmHGeh66-GOZR_ (Video 1 - 12)
- 🌐 &nbsp; ChatGPT: 1 số cách chia file cho hợp lý
- 💻 &nbsp; Lazyfoo

<h3>🛠 Chương trình Game</h3>


- 🔧 &nbsp; 1 số file giống với Youtube: Physics, Object, Timer, Camera
- 🤔 &nbsp; 1 số hàm chứa 1 số tính năng giống với Youtube: MainCharacter, Events, Core, TextureManager
- ✍️ &nbsp; Tự code rất chăm chỉ và không tham khảo: Maps, Menu, Những thuật toán di chuyển nhân vật, xử lý chạm, Traps,...

<h3>🛠 Hoạt động</h3>


- &nbsp; **File Core** chứa class Game để xử lý những thao tác chung (Init, Render, Update, Clean,...)
- &nbsp; **File Object** chứa class GameObject được kế thừa từ IObject có những thuộc tính chung chung gì đó của các đối tượng
- &nbsp; **File Timer, Events, Camera, Animation, Menu** dễ hiểu như tên
- &nbsp; **File Physics chứa các class Vector2D, Point, Transform và RigidBody** để xử lý những thứ liên quan đến vật lý (Lực, vị trí, gia tốc, tốc độ,...)
- &nbsp; **File Sprite** chứa class MainCharacter thừa kế từ Character để khởi tạo nhân vật chính, xử lý di chuyển bay nhảy và những thứ liên quan khác. 
- &nbsp; **File Collision** nghe có vẻ xử lý chạm nhưng chẳng xử lý gì cả, chỉ check chạm thôi =)) Thật hối hận khi code như vậy. Nhưng thuật toán xử lý chạm này tự code và fix mất khá nhiều thời gian, vẫn còn 1 số bug nhưng chưa biết fix lại sao cho hợp lý nhất 🤔
- &nbsp; **File Texture** làm mọi thứ liên quan đến Texture từ Draw, Update, Clean,...
- &nbsp; **File Maps** tự viết nên nhìn có vẻ hơi cồng kềnh nhưng rất dễ hiểu =(( chưa có tối ưu

<h3>🛠 Thuật toán</h3>


- &nbsp; **TileMap**: Tạo 1 file .map chứa 1 đống số được copy từ app Tiled. Class ReadMap đọc những số trong file và lưu thành 1 ma trận có chỉ số hàng và cột, đọc cả file ảnh đã dùng để tạo ra map. Class GameMap để vẽ và làm 1 số thao tác linh tinh. Chạy 2 vòng for để duyệt hết các giá trị của ma trận map. Nếu giá trị = 0 thì bỏ qua, khác 0 thì "cắt" file ảnh thành 1 ô vuông theo công thức:


            - x = (terrainID%22)*tilesize, y = (terrainID/22)*tilesize, cạnh = TILE_SIZE 
            - 22 là số ô của 1 hàng ngang trong file ảnh (ý là cắt ảnh thành 22 cột), terrainID là giá trị của ma trận
- &nbsp; **Di chuyển trái phải**: Tác dụng 1 lực theo phương x
- &nbsp; **Rơi xuống**: Theo gia tốc g (nhưng để rơi chậm hơi thì tác dụng thêm 1 lực đẩy theo phương y) 
- &nbsp; **Nhảy lên**: check xem có ở dưới mặt đất không, nếu không thì chạy 1 vòng for, mỗi lần di chuyển nhân vật 1 đoạn y = -2 :)) Như vậy nhân vật sẽ nhảy lên từ từ =)))))))))))
- &nbsp; **Xử lý chạm**: Từ tọa độ hiện tại của nhân vật, check xem nhân vật đang ở tile nào? (hàng mấy, cột mấy), nếu tile[row][col] có giá trị khác 0 (tile là ma trận của map :<) thì không cho di chuyển nữa. Tất nhiên khi di chuyển, phải check trước vị trí nhân vật di chuyển đến có giá trị tile khác 0 không???????????
- &nbsp; **Xử lý bẫy**: Tương tự như chạm, Nếu nv ở ô có bẫy thì chỉ số int die được cộng dần, nếu đạt đến giá trị 100 thì nv die
...

<h3> ⭐🏻 Thêm </h3>


- &nbsp; Game còn khá nhiều Bug, chưa có enemy như quái vật,.................................. Chưa có xử lý thằng thua, check point, menu pause,...............
- &nbsp; Có thể tiếp tục để hoàn thiện game hơn <3 


Byeeeeeeeeeeeeeeeeeeeeeeee
