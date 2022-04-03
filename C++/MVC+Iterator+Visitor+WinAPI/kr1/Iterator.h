#pragma once
class Iterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() const = 0;
  virtual bool CurrentItem() const = 0;
};
