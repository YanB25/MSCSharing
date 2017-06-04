#include <algorithm>
using namespace std;
class SortByPrice : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size);
};
bool ComPrice(const TaoBaoItem& lhs, const TaoBaoItem& rhs) {
	return lhs.price > rhs.price;
}
void SortByPrice::DoSort(TaoBaoItem item[], int size) {
	std::sort(item, item + size, ComPrice);
}
 


class SortBySales : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size);
};
bool ComSales(const TaoBaoItem& lhs, const TaoBaoItem& rhs) {
	return lhs.volume_of_sales > rhs.volume_of_sales;
}
void SortBySales::DoSort(TaoBaoItem item[], int size) {
	std::sort(item, item + size, ComSales);
}
 
class TaoBao {
 public:
  TaoBao(SortInterface* strategy) : strategy_(strategy) {}
  
  void SetSortStrategy(SortInterface* strategy) {
  	strategy_ = strategy;
  }
 
  // Use current strategy_ to do the sort.
  void sort(TaoBaoItem item[], int size) {
  	strategy_->DoSort(item, size);
  }
 
 private:
  SortInterface *strategy_;
};
